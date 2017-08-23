<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Board Platformer</a>
<ul>
<li><a href="#sec-1-1">1.1. Introduction</a></li>
<li><a href="#sec-1-2">1.2. Features (Planned)</a></li>
<li><a href="#sec-1-3">1.3. Current State</a></li>
<li><a href="#sec-1-4">1.4. Development TODO list</a></li>
<li><a href="#sec-1-5">1.5. Dependencies</a></li>
<li><a href="#sec-1-6">1.6. License</a></li>
</ul>
</li>
</ul>
</div>
</div>

# Board Platformer<a id="sec-1" name="sec-1"></a>

A Board Game AI Developing Platform

## Introduction<a id="sec-1-1" name="sec-1-1"></a>

Board Platformer is a generic board game AI developing platform.
Using this framework, you can implement a board game AI developing platform for any board game.
Refer to the Features below in order to see what this framework offers.

## Features (Planned)<a id="sec-1-2" name="sec-1-2"></a>

These are future plans for the finished version.
It is not guarenteed that these features will make it onto release.


1.  **Play against a game AI**: 
    The framework provides a library for developing your own game AI algorithm.
    Using the provided library, compiling your AI algorithm will result in a player program.
    You can play against your player program via Board Platformer either on CLI or GUI.
    Or others can give their own player program so you can play against it.

2.  **Make an AI play against an AI**: 
    By providing two player programs, Board Platformer can make two AIs play against each other.
    Either on GUI or CLI, you can spectate the game.
    Using this feature it is possible to match your game AI algorithms and others' game AI algorithm.

3.  **Automatically gather gameplay data (of AIs)**: 
    In automatic play mode, Board Platformer will make two player programs play against each other multiple times.
    Detailed gameplay datas will be saved in JSON format so you can use this for training machine learning models.
    Machine learning Methods such as reinforced learning require a ton of data!
    For performance, you can enable multithreaded mode in order to play multiple games in parallel.

## Current State<a id="sec-1-3" name="sec-1-3"></a>

Board Platformer is currently under very early development.
The project is not even close to partially done, Everything is subject to change.
Contributers are very welcome. However ask me first before jumping in.

My personal development environment is Linux.
Thus no support for different platforms are available.
If your willing to contribute from a different platform,
you'll first have to successfully create a build system of your own.
(this alone will be a create contribution!)

## Development TODO list<a id="sec-1-4" name="sec-1-4"></a>

-   [X] Logging System
-   [X] Platform Interface
-   [ ] Core System
-   [ ] Player Program Library
-   [ ] GUI
-   [ ] CLI
-   [ ] Automatic Play Mode
-   [ ] Example Implementation (In Go, Connect6, Connect5, Chess, etc..)

## Dependencies<a id="sec-1-5" name="sec-1-5"></a>

-   [grpc](https://grpc.io)
-   [protobuf](https://developers.google.com/protocol-buffers/)
-   [nana](http://nanapro.org/en-us/)
-   [boost](http://www.boost.org/)
    -   [filesystem](http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/index.htm)
    -   [system](http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/index.htm)
    -   [process](http://www.boost.org/doc/libs/1_64_0/doc/html/process.html)
    -   [asio(planned)](http://www.boost.org/doc/libs/1_64_0/doc/html/boost_asio.html)
-   threads
-   standard filesystem

## License<a id="sec-1-6" name="sec-1-6"></a>

Board Platformer. A Board Game AI Developing Platform                     
Copyright (C) 2017  Red-Portal                                            

This program is free software: you can redistribute it and/or modify  
it under the terms of the GNU General Public License as published by  
the Free Software Foundation, either version 3 of the License, or     
(at your option) any later version.                                   

This program is distributed in the hope that it will be useful,       
but WITHOUT ANY WARRANTY; without even the implied warranty of        
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
GNU General Public License for more details.                        

You should have received a copy of the GNU General Public License     
along with this program.  If not, see <http://www.gnu.org/licenses/>.
