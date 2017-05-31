# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program
 
---
 
---
## Environment and Objective 
The goal of the project is to design a system that drives a car autonomously in a simulated environment. We are provided with the Udacity self-driving car simulator. This way a car can be piloted in  a virtual environment based on measurement data. The simulator produces an error  known asl Cross Track Error (CTE). The CTE indicates the difference between the car's actual position and the optimal position at the lane center.
 
## Approach
A proportional–integral–derivative controller (PID controller) is used as a control loop feedback mechanism to minimize the CTE. This project only focuses on the steering angle as output of the PID controller. 
The PID controller applies a steering correction based on proportional, integral, and derivative terms. All three terms will be multiplied by a constant to define their impact on the output steering angle. Let's take a closer look at the significance of each term.
 
* **P - Proportional Term**
  
  The proportional term accounts for the present values of the error. It is the most obvious term. It is purely proportional to the current error measurement. A pure P controller gave very unstable results. The car would constantly overshoot the desired position and oscillate about the optimum. If we increase the weight of the proportional term the amplitude of the oscillation increases. This means the car will eventually go off the road after some drunk zigzag driving.
 
 
* **I - Integral Term**
  
  The integral term accounts for past values of the error. Instead of using the sum of all past errors a moving average of the recent 100000 measurements is used. This avoids that the integral term can grow too big. This is important because even though the integral gain is given a relatively small weight, it is purely accumulative and would grow too big eventually.
 
* **D - Derivative Term**
  
  The derivative term accounts for possible future trends of the error. This proved to be very powerful. Curves on most roads follow a steady trend. This is why the derivative is reliable to make predictions. Although if we give the derivative term too much weight the frequency of the oscillation increases and we and up with a high frequency zig zag with a small amplitude.
 
 
## Hyperparameter Tuning
All parameters were tuned manually. Here is my approach:
 
I started out giving the derivative gain `Kd` the biggest weight and both the integral and proportional gain were set to a relatively small initial value. The initial values were:
 
`Kp = 0.5, Ki = 0.5, Kd= 10.`
 
This decision was based on the believe that the derivative gain would be the most reliable term. 
As said above road curves follow a steady trend and the derivative proves to be good estimator for curvature. 
 
In the next step `Kp` and `Ki` were fine-tuned. 
`Kp` proved to have a huge influence on the amplitude of the oscillation and decreasing `Kp` lead to a steadier driving with smaller zig zag. `Ki` was also decreased because the it resulted that the driving behaviour was more reactive with a smaller `Ki`. This was important especially for higher velocities.
 
The final values are:
 
`Kp = 0.2, Ki = 0.0005, Kd= 10.`
 
 
## Dependencies
 
* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.
 
## Basic Build Instructions
 
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
 
## Editor Settings
 
We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:
 
* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)
 
## Code Style
 
Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).
 
## Project Instructions and Rubric
 
Note: regardless of the changes you make, your project must be buildable using
cmake and make!
 
More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.
 
## Hints!
 
* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.
 
## Call for IDE Profiles Pull Requests
 
Help your fellow students!
 
We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.
 
However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:
 
* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md
 
The README should explain what the profile does, how to take advantage of it,
and how to install it.
 
Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.
 
One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
 
 
