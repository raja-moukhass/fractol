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

### Output
The program will render a fractal in a new graphical window!
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/mandelbrot.png)
![Example of burningship:](https://github.com/raja-moukhass/fractol/blob/master/images/burningship.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/mandlebrot.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/julia.png)
![mandelbrot:](https://github.com/raja-moukhass/fractol/blob/master/images/iteration.png)






### sources
- https://github.com/keuhdall/images_example
- https://github.com/qst0/ft_libgfx
- http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html?fbclid=IwAR0abKda4KXEbe7Cle1rxME04v48rH4WvZR10jhebNGEQd2yZVU0bfX2mN0(the most important )
- http://villemin.gerard.free.fr/Wwwgvmm/Suite/FracComp.htm 
- https://stackoverflow.com/c/42network/questions/164/166
- https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand
- https://github.com/nmei-42/42-Fractol/blob/master/minilibx/man_mlx_new_image.md
- https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c
- http://warp.povusers.org/Mandelbrot/
- https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/
- http://sdz.tdct.org/sdz/dessiner-la-fractale-de-mandelbrot.html?fbclid=IwAR0abKda4KXEbe7Cle1rxME04v48rH4WvZR10jhebNGEQd2yZVU0bfX2mN0
- https://qst0.github.io/ft_libgfx/man_mlx_new_window.html (man)
- https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c (zoom)
- https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean (MAKEEFILE stackoverflow)
- https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#using (makefile)
- https://www.tenouk.com/ModuleW.html
- https://www.geeksforgeeks.org/cc-preprocessors/
- https://www.tenouk.com/ModuleZ.html
- https://www.tenouk.com/Sitemap.html
- file:///Users/ramoukha/Downloads/FdF%20Cookbook%20(1).webarchive
### videos sources
- https://youtu.be/Y4ICbYtBGzA (FR)
- https://youtu.be/iFA3g_4myFw (FR)
- https://youtu.be/2JUAojvFpCo (EN)
- https://www.youtube.com/watch?v=0YaYmyfy9Z4&ab_channel=fenby1976 (this is the Greatest video you can watch)

- https://youtu.be/MwjsO6aniig (EN)


-https://github.com/abhisheknaiidu/awesome-github-profile-readme#dynamic-realtime- (github )
