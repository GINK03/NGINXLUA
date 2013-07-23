PWD=`pwd`/
echo "default user path"
echo $PWD
g++-4.8 -std=c++11 -fPIC -shared -fpermissive \
  Template.cpp \
  Berkley.cpp \
  -I/usr/include \
  -L/usr/lib/i386-linux-gnu/ -ldb_cxx-5.1 \
  -L$PWD../leveldb-1.12.0 -lleveldb -Wl,-rpath,$PWD../leveldb-1.12.0 \
  -o libmodule.so
g++-4.8 -std=c++11 -fPIC -fpermissive \
  Template.cpp Berkley.cpp Level.cpp ../tests/main.cpp \
  -I/usr/include -I../leveldb_1.12.0/include \
  -L/usr/lib/i386-linux-gnu/ -ldb_cxx-5.1 \
  -L$PWD../leveldb-1.12.0 -lleveldb -Wl,-rpath,$PWD../leveldb-1.12.0 \
  -o a.o 
