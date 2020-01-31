The code in this project build a server that waits for clients,reads problems from them,solves the problem and returns the answer.
the sturcture of the code is built in a way that allow you to change between different implemitions, and even enables you to make your own.
to make this possible,each part of the code handles different functions in a certain area.we implemented them in the generic way based on the SOLID fundamentals.

in genera,there are four generic parts to the code that can be implemented in different ways:

'server'- this class builds the server,handels any client that connects,and how many. all the features that a server can have are implemented in this class. 
in our project we implemented two server types. the first one is a serial server that handles clients one after another.while the program listens to a client and communicate with it,any other client that wants to connect to the server,waits.
the second server type is a parallel server. it allows to muilti clients to connect to him and handles all of them in the same time with the help of threads.
other server types can be added and implemented,the only thing that must be in common to all servers is that it sends the problem from the client to a certain clientHandler.

'handlerClient' - this class gets the client port from the server and his responsibility is to read output from the client and act upon it.
based on what the client sends,it can end the communication or,based on two basic variables that act as the fundamentals of how it acts-return a solution of a problem to the client. the first variable is a cache manager and the second one is a solver. the general behavior of a handlerClient is to ask a cacheManager if a solution to a specific problem is already saved,and if not to run a solver that will solve the problem. 

'cache manager' - a class that saves any problem that got sent to the server with its solution. we implemented one type of a cache manager that saves a problem and solution in a file on the same folder of the project and in a cache.

'solver'-a class that gets a problem from a client handler and active some type of a problem solver algorithm,and than returns the solution to the client handler. 

in this project,in addition of adding this generic structure for making a problem-solver server more easier - we implemented two types of solvers. the first one is a solver that get a string and returns the reverse of it. the second solver is called a matrix solver,and it gets a matrix,a start point and an end point- and returns the shortest path from the start to the end. 
In our implemention we wanted to keep the type of matrix solver generic too,for cases we want to use muilti algorithms to solve a problem. we recommend to follow this structure. in this case we implemented it with a generic search and searchables templates.


To run the proggram-download all the files in the project and in the main.cpp class write the following structure:

New Server(int port,new clientHandler(new cacheManager,new solver))

as you can see,the builder of server gets a port and a client handler, and the builder of a client handler gets a change manager and a solver.

as a last step,write server->open to open a server and start listening to any client that connects to it. the code from this point can be activeted and handle itself-it will get problems,solve them and save them in the cache manager.

-Project made by Sahar Ben-Yitzhak and Eyal Brilling.
github profiles:
https://github.com/SaharBe
https://github.com/EyalBrilling





