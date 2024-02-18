# QuadHawk Onboard

KU 2024 Senior design project for AirHawks group. Our goal is to make an airborne radar capable device with autonomous flying capabilities for traffic monitoring and speed limit enforcement.

## Description

An in-depth paragraph about your project and overview of use.

## Getting Started

### Dependencies

* Install Docker, [Windows](https://docs.docker.com/desktop/install/windows-install/), [Linux](https://docs.docker.com/desktop/install/linux-install/)


### Installing

1. Clone this repo: Open a terminal and run in your desiered download location
    ```
    git pull https://github.com/KU-AirHawks/QuadhawkOnboard.git
    ```
2. navigate to project folder
    ```
    cd QuadHawkDrone
    ```
3. ensure docker is running
    ```
    sudo systemctl start docker
    ```
    If on windows open docker desktop and look for the green bar in the bottom left of the screen

4. Build the docker image (This will take a very long time ~2 hours)
    ```
    docker compose build
    ```

### Starting and getting into the docker container
* To start the docker container, in the same directory as compose.yaml run
    ```
    docker compose up -d
    ```
* To get into the docker container
    1. find the CONTAINER ID by runing the fallowing and getting the ID of the container you want to get into
        ```
        docker ps
        ```
    2. get into a container terminal
        ```
        docker exec -it <CONTAINER ID> bash
        ```
    3. while in the container shell you can exit and get to the host shell at any point by simply typing
        ```
        exit
        ```
* to stop your docker container to make changes or stop working run 
    ```
    docker compose down
    ```


### Executing program

* How to run the program
* Step-by-step bullets
```
code blocks for commands
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)