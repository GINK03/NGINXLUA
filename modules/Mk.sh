g++-4.8 -std=c++11 -fPIC -shared -fpermissive Template.cpp -o libmodule.so
g++-4.8 -std=c++11 -fPIC -fpermissive Template.cpp Berkley.cpp -I/usr/include -L/usr/lib/i386-linux-gnu/ -ldb_cxx-5.1 -o a.o
