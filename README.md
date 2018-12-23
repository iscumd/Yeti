# Yeti2019
Yeti X: Ka-plow!

##For Simulation!!

0. Make sure you build the Yeti2019 repo beforehand, according to the instructions below
1. Update your Gazebo Version. (http://gazebosim.org/tutorials?cat=install&tut=install_ubuntu&ver=7.0#Alternativeinstallation:step-by-step)
2. `sudo apt-get install ros-kinetic-gazebo-ros-pkgs ros-kinetic-gazebo-ros-control`
3. `cd catkin_ws`
4. `source devel/setup.bash`
5. `roslaunch yeti_snowplow start_simulation.launch`


##Building the Repo
1. Download and build [iscumd/SharedROSNodes](https://github.com/iscumd/SharedROSNodes) (follow the instructions on that page)
2. Open a console and source your catkin workspace if you haven't already
3. Change directory to `your_catkin_workspace/src` if you haven't already.
4. Run `git clone https://github.com/iscumd/Yeti2019.git`.
5. Run `rosdep install yeti_snowplow`. This should install any missing package dependancies.
6. Run `catkin_make` to build the package.
