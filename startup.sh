#!/bin/bash

echo "STARTING..."

docker compose -it --rm --user=$(id -u $USER):$(id -g $USER) --env="DISPLAY" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" osrf/ros:indigo-desktop-full