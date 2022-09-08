# robotic-arm-simulation

This a software program involving the design of a software to simulate the motion of a multi-degree of freedom kinematic chains or segments also known as limb that form the structure of a robotic system. The emphasis on geometry means that the links of the robot are modeled or simulated as rigid bodies and its joints are assumed to provide pure rotation or translation

# relevant information

A segment: A segment is a rigid member  connecting two joints. A segment has the following parameters: a starting point (x1 and y1 coordinates), a length, an angle (different technique may have different references for measuring the angle for a segment, so make your assumption clear), and an endpoint (x2 and y2 coordinates). Note that the coordinates of the end point can be calculated given the start point coordinates, the length, and the angle.

A Robot: A robot is comprised of a chain of segments that are connected via joints. The first segment is called the root as it is connected to the robot base/ground. A robot can have multiple segments, which is commonly known as the degrees of freedom. The end effector of the robot is the end point of the last segment. To determine the position of the end effector, the position/orientation of all the segments must be determined – which is usually controlled through the angles of the segments. The forward kinematic analysis involves calculating the end effector position for a specific set of angles for the segments. The inverse kinematics analysis involves calculating the angles of all the segments that move the end effector to a particular position
