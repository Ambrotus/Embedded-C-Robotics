# Embedded-C-Robotics
Small programs for robots!

## TurningAndDirectionCorrecting


TurningAndDirectionCorrecting.c showcases diagnosing and trouble shooting a faulty motor. The motor on the robot here is slower than the one on the opposite side I  corrected this by using the gyro sensor to notice any drift, from there I sped up the one side that has the faulty motor to keep the path as straight as possible.
90 degree turns where the same. I had to have the left motor at a higher speed than the right. It still didn’t work all that great at first, so I did a big quick turn until the gyro sensor reported it was within an acceptable range. From there I adjusted the turn slowly until the gyro sensor reported it was within +/- 5 degrees on either side of the expected 90 degree turn.


## LineFollowingAndObjectGrabbing


LineFollowingAndObjectGrabbing.c showcases detection and following of a complex line. It also took the concept of correcting the drift from my other project TurningAndDirectionCorrecting.c that had a faulty motor and built upon it using a proper concept of Automated Straightening using encoders. I have also modified all my 90 degree turn functions to use encoders instead of a fine/crude controlled turn using gyros that I had come up with in a simalar fashion to the drift correcting concept I had come up with while troubleshooting. This project Starts in a black box and needs to find a line, follow it, grab an object at the end of the line, and return back down the line to the start location and drop the object.

![image](https://user-images.githubusercontent.com/43772313/89460837-f19d9c00-d738-11ea-9ca3-d458549eacd6.png)
![image](https://user-images.githubusercontent.com/43772313/89460896-1560e200-d739-11ea-8c79-369cfe8afb26.png)



The first program, TurningAndDirectionCorrecting was made to move through a small 3 turn maze. Here I noticed my robot had a faulty left motor which needed constant adjustments when moving. I devised a function to autocorrect the movements based on gyroscope sensor data. If it noticed any degree of change after a quick movement, it would then correct this by increasing the corresponding motor’s speed. Each ninety degree turn also needed to have a similar correction otherwise the sonar sensor would detect the wrong walls and fail to navigate the maze. The next program LineFollowingAndObjectGrabbing both furthers and simplifies concepts I created in the first program and introduces a few more. Here we utilize additional encoders,   line-follower sensors on top of the gyroscope and sonar sensors. I also improved on the first programs course adjustments and turns using encoders for more precision as well as modifying them to be universal for any robot I used.
 These allow the robot to detect the line shown in the pictures of the readme and avoid the ones in the start box. The robot then follows the line to the object,
