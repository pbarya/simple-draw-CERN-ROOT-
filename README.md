# simple-draw-CERN-ROOT-
Interactive drawing,  assuming cern root installed. 
  
This is simple drawing code. Can draw simple 2D graph and histogram using any data file. This has some 
interactive features and it can be used by a layman. 
You need to do the following (Unix): - 
1) simply download the code and run with root -l tulika.c

OR (location independent run) 

1) Open the terminal and go to the directory where you saved this code. 
2) type pwd is terminal and note the output it should be "/home/.... /"
3) now type    vi ~/.bashrc     in terminal (Or your prefered editor like gedit etc.). 
 Add this line in your bashrc file: 
alias tulika="root -l  /home/.../tulika.C"
Note "/home/.../" is your directory path where you have saved this code
save and exit. 
5) Close your terminal. 
All set . 
Now you can open a new terminal and just type tulika it should work! 
