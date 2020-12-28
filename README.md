# 42-Fractol
Exploring the wonderful world of fractals with the 42 mlx library.

This program will generate a number of escape time fractals with the ability to zoom, cool color animations, and in some cases, mouse interactivity!
# Installation
To generate an executable for this project run make in the root of the project directory after you've downloaded or cloned it.

This project will only work on MacOS El Capitan/Sierra/HighSierra and even then, no promises!

### how to run the project 
Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

you can generate the fractol executable you can run the program with ```./fractol [fractol option]```

here is the liste of possible fractals that this program can display:
```
0) mandelbrot
1) julia
2) Burning Ship
3) tricorn 
```

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Enable or disable the mouse controls</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kbd>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the up (aka move up)</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the down (aka move down)</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the left (aka width move left)</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the right (aka move right)</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the numbre of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
</tbody>
</table>

## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;left button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal at the position of the cursor</td>
<td valign="top" align="center"><kbd>&nbsp;right button&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the global size of the fractal (aka zoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the fractal (aka unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>

### key hook 
<img src="https://github.com/raja-moukhass/fractol/blob/master/images/hook.png" alt="Computer Man" style="width:48px;height:48px;">

### Output
The program will render a fractal in a new graphical window!
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/mandelbrot.png)
![Example of burningship:](https://github.com/raja-moukhass/fractol/blob/master/images/burningship.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/mandlebrot.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/julia.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/iteration.png)






# sources

### mlx
- <a href="https://github.com/keuhdall/images_example">A simple example program made for the 42 students going into the graphic branch</a>
- <a href="https://github.com/qst0/ft_libgfx"> explaining and looking into the 42 School Graphics Library Minilibx</a>
- <a href="https://qst0.github.io/ft_libgfx/man_mlx_new_window.html"> man mlx</a>


### Tutoriel : Dessiner la fractale de Mandelbrot
- <a href="http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html?fbclid=IwAR0abKda4KXEbe7Cle1rxME04v48rH4WvZR10jhebNGEQd2yZVU0bfX2mN0">draw mandelbrot</a>
- <a href="https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand">How to Plot the Mandelbrot Set By Hand</a>
### zoom
- <a href="https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c">smooth zoom with mouse</a>
### makefile and compilation 
- <a href="https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#using">Makefile</a>
- <a href="https://www.tenouk.com/ModuleW.html">COMPILER, ASSEMBLER, LINKER AND LOADER:
A BRIEF STORY (TOOOOOOOP)</a>
- <a href="https://www.geeksforgeeks.org/cc-preprocessors/">C/C++ Preprocessors</a>
### videos sources
- <a href="https://www.youtube.com/watch?v=0YaYmyfy9Z4&ab_channel=fenby1976">what the Mandelbrot set is, assuming only basic mathematical knowledge</a>
- <a href="https://www.youtube.com/watch?v=NGMRB4O922I&t=15s&ab_channel=Numberphile">Famously beautiful, the Mandelbrot Set is all about complex numbers. Featuring Dr Holly Krieger from MIT</a>
- <a href="https://www.youtube.com/watch?v=FFftmWSzgmk&t=425s&ab_channel=Numberphile">Featuring Ben Sparks discussing the Mandelbrot Set (and Julia Sets). Catch a more in-depth </a>
- <a href="https://www.youtube.com/watch?v=fAsaSkmbF5s&t=605s&ab_channel=TheCodingTrain">In this coding challenge,programing from the Julia Set fractal in Processing (Java).</a>
### if you want to make a awesome readme like this :hand_over_mouth:
- <a href="https://github.com/elangosundar/awesome-README-templates">Awesome-README-templates</a>
- <a href="https://github.com/abhisheknaiidu/awesome-github-profile-readme#dynamic-realtime-">Awesome-github-profile-readme</a>

