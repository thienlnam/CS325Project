# CS325 Final Project

<b>Project Group 37</b>
- Thien Nam
- Cristian Mann
- Jonathan Iniguez

We implemented the Nearest Neighbor Algorithm for our assignment.  In this algorithm, the salesman starts at a random city and repeatedly visits the nearest city until all have been visited.

The program takes a test-input file, and exports the results into a test-input.tour file.  

<b>Compiling:</b> g++ nna.cpp -o nna

<b>Running:</b> ./nna [input_file]

<b>Verifying:</b> python tsp-verifier.py [input_file] [result_file]
