prog=program6

make

for i in $(find tests/ -type f -print)
do
    echo ""
    echo $i
    ./$prog < $i
    echo ""
done