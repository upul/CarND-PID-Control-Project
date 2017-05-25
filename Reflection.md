## The effect of P, I and D components of the PID Controller

Using the Cross Track Error (CTE) P component of the PID controller gives the correct steering angle. However, P itself will not reach the exact target and will cause a lot of overshoot and oscillations. So P controller is not enough for safe driving.

In order to mitigate these issues, we can introduce D component to our controller. D component captures the temporal difference of the CTE. So it helps to safely and smoothly navigate the car to the target. 

Finally, the I component is proportional to both magnitude and duration of the CTE. Hence, I component helps to move the car towards the target trajectory and helps to reduce the drift. 

### Hyper-Parameter Optimization

Before running the PID controller algorithm, we have to select correct values of the Kp, Ki and Kd parameters. Hence, these three parameters are known as hyper-parameters of the algorithm. 

#### The Intuition Behind the Selecting Initial Value for Kp, Ki and Kd.

Since I component of the PID controller considers sum of all error from the starting point of the car we normally use very small very for the Ki.

On the other hand for Kp we can use a little bit higher value. However, if the car starts to oscillate it will be a good idea to reduce the value of Kp .

Finally, we use a number that is larger than one for the Kd. If  Kd is greater than one, it is possible to observe some rapid oscillation in CTE and that helps the car to take turns. 

#### Hyper-Parameter Optimization using Grid Search

With the above intuition, I used following values for Kp, Ki and Kd.

 Kp|  Ki|  Kd
---|---|---
 0.1 |0.001|2.0 
 0.2 |0.002|4.0 
 0.3 |0.003|8.0 
 
For each combination of Kp, Ki and Kd I ran the simulator and observed the driving behavior of the car and finally selected following values

Kp| Ki| Kd
---|---|---
 0.1|0.002|4.0

The following video shows how the car is navigating on the track using selected hyper-parameters.

<p align="center">
    <a href="https://www.youtube.com/watch?v=WrJ1URxloY0">
        <img src="https://img.youtube.com/vi/WrJ1URxloY0/0.jpg" alt="video output">
    </a>
</p>
