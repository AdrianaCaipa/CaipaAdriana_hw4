Resultados_hw4.pdf: Promedio_f.png Promedio_p.png Promedio_l.png Temperatura_f.png Temperatura_estadof.png Temperatura_estado2f.png Temperatura_estadofinf.png Temperatura_p.png Temperatura_estado1p.png Temperatura_estado2p.png Temperatura_estadofinp.png Temperatura_l.png Temperatura_estadol.png Temperatura_estado2l.png Temperatura_finl.png Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
	rm *.png
	rm *.txt
	rm *.out
Promedio_f.png Promedio_p.png Promedio_l.png Temperatura_f.png Temperatura_estadof.png Temperatura_estado2f.png Temperatura_estadofinf.png Temperatura_p.png Temperatura_estado1p.png Temperatura_estado2p.png Temperatura_estadofinp.png Temperatura_l.png Temperatura_estadol.png Temperatura_estado2l.png Temperatura_finl.png: Plots_hw4.py promedio_f.txt promedio_p.txt promedio_l.txt temperatura_f.txt temperatura_p.txt temperatura_l.txt 

Plots_hw4.py promedio_f.txt promedio_p.txt promedio_l.txt temperatura_f.txt temperatura_p.txt temperatura_l.txt: ODE.cpp PDE.cpp
	g++ ODE.cpp
	./a.out
	g++ PDE.cpp
	./a.out
