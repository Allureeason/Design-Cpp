for cfile in $(ls *.cpp)
do
    path="bin/"${cfile%.*};
    g++ ${cfile} -std=c++11 -o ${path}
    echo output $path
done
