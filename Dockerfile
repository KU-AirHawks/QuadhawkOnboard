FROM ubuntu:20.04 as base

### Stage 1 - add/remove packages ###
RUN ls

COPY ./droneFlight /home/airHawk/droneFlight
COPY ./signalProcessing /home/airHawk/signalProcessing
COPY ./systemControl /home/airHawk/systemControl
# - Symlink variant-specific scripts to default location
# - Upgrade base security packages, then clean packaging leftover
# - Add S6 for zombie reaping, boot-time coordination, signal transformation/distribution: @see https://github.com/just-containers/s6-overlay#known-issues-and-workarounds
# - Add goss for local, serverspec-like testing
RUN apt-get update && \
    apt-get install -y \
    bash \
    sudo \
    python \
    ros-iron-desktop \
    && \
    ls

# Overlay the root filesystem from this repo



### Stage 2 --- collapse layers ###

# FROM scratch
# COPY --from=base / .

# CMD ["/bin/bash", "/run.sh"]