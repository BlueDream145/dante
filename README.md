# dante
Epitech Project, dante


![alt text](https://raw.githubusercontent.com/alexandre10044/dante/master/generator_demo.png)

![alt text](https://raw.githubusercontent.com/alexandre10044/dante/master/solver_demo.png)


Subject:

You must have 3 folders : solver with a binary named “solver” in it, generator with binary named “generator”
in it and a folder tournament with the binaries that you want to enroll for the tournament.
Each folder must contain a Makefile compiling the binary and a Makefile at the root must compile all binaries.

solver generator Makefile tournament

./ solver :
solver

./ generator :
generator

./ tournament :
solver
generator

The solver in “tournament” will be used for the tournament.
Each solver must be able to function as follows:

∼/B-IIA-150> ./solver maze.txt

and print the solved maze on the standard output.
If there is no solution you must print “no solution found” on the same output.
The generator must function as follows:

∼/B-IIA-150> ./generator x y [perfect]

As the perfect argument is optional, the default generation will be an imperfect maze.
