# Feed-Parser
Robust RSS, Atom Feed Parser written in C++

When I was looking into various C++ Feed Parsers, not many were as useful or did not have a good documentation.
So I went ahead and started creating my own Feed Parser.
This library is heavily based upon C++14

##Dependencies

This library requires libcurl for curl.h

``sudo apt-get install libcurl-dev``

##Installation

Clone this repository and
```
    cd FeedParser
    cmake .
    make
    sudo make install
```

To use,

include the header file ```Feedparser/feed.h``` in your project and compile with the flags

 ``-lcurl -pthread -lFeedparser``


## Advantages

 - It uses threads to manage the downloading process.
 - The images downloaded are stored in memory and can be accessed very easily for use with other
 - Very low memory usage
 - Customized for all feed types


Report by creating a issue if the library doesn't work for any feed.

Hats off to @hjiang and @Cheedoong for their great libraries

[jsonxx](https://github.com/hjiang/jsonxx)

[xml2json](https://github.com/Cheedoong/xml2json)

##TODO

I need to cleanup the entire code and also include more commenting here and there.
