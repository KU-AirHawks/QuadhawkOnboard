FROM ubuntu:20.04 as base


# add our code into the contianer
COPY ./droneFlight /home/airHawk/droneFlight
COPY ./signalProcessing /home/airHawk/signalProcessing
COPY ./systemControl /home/airHawk/systemControl


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
    && apt-get clean all

# set up PX4 enviornment
RUN cd &&\
    git clone https://github.com/PX4/PX4-Autopilot.git --recursive &&\
    bash ./PX4-Autopilot/Tools/setup/ubuntu.sh &&\
    # echo "ran bash commands" &&\
    cd PX4-Autopilot/ &&\
    make px4_sitl &&\
    cd


# 

# Overlay the root filesystem from this repo



### Stage 2 --- collapse layers ###

# FROM scratch
# COPY --from=base / .

# CMD ["/bin/bash", "/run.sh"]