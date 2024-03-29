FROM ubuntu:20.04 as base


# add our code into the contianer
COPY ./onboard_ws /home/airHawk/onboard_ws
ENV DEBIAN_FRONTEND=noninteractive


# install our packages
RUN apt-get update && \
    apt-get install -y \
    lsb-release \
    bash \
    git \
    sudo \
    python3 \
    gnupg2 \
    wget \
    curl \
    aptitude \
    && apt-get clean all

# set up PX4 enviornment
RUN ls &&\
    # git clone https://github.com/PX4/PX4-Autopilot.git --recursive &&\
    bash /home/airHawk/onboard_ws/src/PX4-Autopilot/Tools/setup/ubuntu.sh &&\
    cd ./home/airHawk/onboard_ws/src/PX4-Autopilot/ &&\
    make px4_sitl &&\
    cd 
    
# install Ros
RUN apt update && \
    apt install locales &&\
    locale-gen en_US en_US.UTF-8 &&\
    update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 &&\
    export LANG=en_US.UTF-8 &&\
    apt install -y software-properties-common &&\
    add-apt-repository universe &&\
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg &&\
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null &&\
    sudo apt update &&\
    sudo apt upgrade -y &&\
    sudo apt install -y\ 
    ros-foxy-desktop \ 
    python3-argcomplete \
    ros-dev-tools

#run commands that we need but px4 and ros dont need
RUN apt update && \
    apt-get install -y \
    firefox \
    vim

# Overlay the root filesystem from this repo



### Stage 2 --- collapse layers ###

# FROM scratch
# COPY --from=base / .

# CMD ["/bin/bash", "/run.sh"]
