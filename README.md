# podcast-network

This project mimics a podcast network. Note there is no UI associated with this project. 

Overview: 
Podcasts have a title and a host and a data structure for storing 0 or more Episodes. Each episode will have some metadata and some content. Episodes may then be “played” (i.e., have their content printed to the console).

The Network itself will consist of 0 or more Podcasts as well as 0 or more Subscribers. A Client class will be able connect to the Network as long as the Client name matches a Subscriber name. Once they connect they can “stream” episodes from any podcast. In addition, a Client will be able to “download” podcasts. This copies the podcast to “local storage”, which is a data structure in the Client class. Subscribers can then play the podcast locally, and this should work even if the network deletes the original podcast.

Instead of connecting remotely, there is a TestControl object to test the functionality of the Network and Client classes by simulating a remote connection. You will then be able to run various tests using the TestControl and TestView objects.


To run: Type make into terminal, then ./a2 to execute. Choose a number 0-5 to run tests.

Note: Must have GCC complier with C++ atleast version 2011 installed.
