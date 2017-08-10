<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Board Platformer</a>
<ul>
<li><a href="#sec-1-1">1.1. Introduction</a></li>
<li><a href="#sec-1-2">1.2. Current State</a></li>
<li><a href="#sec-1-3">1.3. Development TODO list</a></li>
<li><a href="#sec-1-4">1.4. Dependencies</a></li>
</ul>
</li>
</ul>
</div>
</div>


# Board Platformer<a id="sec-1" name="sec-1"></a>

A Board Game AI Developing Platform

## Introduction<a id="sec-1-1" name="sec-1-1"></a>

Board Platformer is a generic board game AI developing platform.
It supports manually playing agains provided AI process.
And also automatic play for gathering stacks of game data.

## Current State<a id="sec-1-2" name="sec-1-2"></a>

Board Platformer is currently under very early development.
The project is not even close to partially done, Everything is subject to change.
Contributers are very welcome, However ask me first before jumping in.

My personal development environment is Linux.
Thus no support for different platforms are available.
If your willing to contribute from a different platform,
you'll first have to successfully create a build system of your own.
(this alone will be a create contribution!)

## Development TODO list<a id="sec-1-3" name="sec-1-3"></a>

1.  [-] Logging system
2.  [ ] Game server
3.  [ ] GUI
4.  [ ] Automatic Play
5.  [ ] Example Implementation

## Dependencies<a id="sec-1-4" name="sec-1-4"></a>

-   [grpc](https://grpc.io)
-   [protobuf](https://developers.google.com/protocol-buffers/)
-   [nana](http://nanapro.org/en-us/)
-   [boost](http://www.boost.org/)
    -   [filesystem](http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/index.htm)
    -   [system](http://www.boost.org/doc/libs/1_64_0/libs/filesystem/doc/index.htm)
    -   [process](http://www.boost.org/doc/libs/1_64_0/doc/html/process.html)
-   threads
-   standard filesystem
