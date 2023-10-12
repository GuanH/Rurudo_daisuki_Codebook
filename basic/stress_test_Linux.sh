set -e
for ((i=0;i<300;i++))
do
    echo "$i"
    python gen.py > input
    ./ac < input > ac.out
    ./wa < input > wa.out
    diff ac.out wa.out || break
done
