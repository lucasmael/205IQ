# 205IQ
Epitech Project, MATHS 205

Subject:

Most of the reference curves, such as weight and height cruves, are created using Gaussian distributions.These curves appear to correctly describe “normality”, and that is why the Gaussian distribution is also callednormal distribution. A normal distribution is described by its mean valueμand standard deviationσwiththe following probability density function:

   f(x) =1σ√2πe−(x−μ)22σ2
    
IQ tests are calibrated so that the results follow a normal distribution. For historical reasons, the mean is al-ways equal to 100, and the standard deviation is usually 15 but can vary (24 in the Cattell test, for example).The interpretation of the resulting IQ obviously depends on the calibration of the test.

Your psychiatrist, Dr Von Humleit, plans to create his own IQ test, which is supposed to be better suited tothe current population than the classical tests from previous centuries. To help him calibrate his test, youhave to program the following tasks:
  •givenμandσ, plot the density function of the IQ for every integer between 0 and 200,
  •givenμ,σand one IQ value, print the percentage of people with an IQ inferior to this value,
  •givenμ,σand two IQ values, print the percentage of people with an IQ in between those values
  
  Usage:
  
  ./205IQ u s [IQ1] [IQ2]
  
  u       means standard deviation
  IQ1     minimum IQ
  IQ2     maximum IQ
  
  Example:
  
  
![alt text](https://github.com/alexandre10044/205IQ/blob/master/example.png?raw=true)
