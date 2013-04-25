/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name: TAN Shuhao
Login: stanab
Hours to complete assignment (optional): 12 hours



/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
Use four nested loops to examine every four-tuple of points. If the four
points form a line, add it to a deque to save the result.

Three methods are added to Point (except for those inherited from Vector2D)
  isCollinear: used to judge wheter three points are on a same line
  draw: draw the point on a given QWidget
  drawTo: draw a line on a given QWidget

Inherited from Vector2D
  dot: dot product of vector
  cross: cross product of vector
  getX, getY, setX, setY: proxy to get or set data

/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
Make each point as origin once, and sort the other relative to the point.
An slight optimization is that if a point does not contribute to any new line,
it will no longer join the sorting later.
The Comparator is implemented using cross product of Vector.
First do a pre-process to substract each point by the current origin.
In the Comparator, invert the vector if it lies in [-pi, 0).
Then use cross product to determine the relative position.

The Point is the same as in Step 1.

To get a minimal representation. A pre-sort by the absolute coordinate
of the points is applied. So in the later iteration, the left-bottom most
point will be the first to iterate of a line. If a point forms a line but 
it is not the left-bottom most point, this line will be discarded.

/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10       0.00        0.00
     20       0.00        0.00
     40       0.00        0.00
     80       0.00        0.00
    100       0.00        0.00
    150       0.00        0.00
    200       0.01        0.00
    400       0.10        0.02
   1000       1.53        0.06
   2000       12.25       0.26
   4000       101.31      1.11
  10000       N/A         8.80


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute: 12,548.9 years
Sorting: 36.67 hours



/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute: O(N^4)
Sorting: O(N^3)

Brute: four nested loops cost O(N^4) times of calculation in worst case.
Sorting: because of using quick sort, the worst case for quick sort
  is O(N^2). Each point need to be set as an origin. Suppose very unfortunately
  every sort is worst, the worst-case is O(N^3)

/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
Currently nope.


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
GAN Bo and CAO Junhong (friends of CSE, not classmates)
We discussed how to optimize the constant coefficient of the program

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The implementation is not so hard. However, to get the algorithm the most
of itself is hard. That is, implement the algorithm with a rather 
little constant. Some trade-off are done due to this reason.

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
This is quite challenging.

