prog=program6

make

for i in $(find test_files/ -type f -print)
do
    echo ""
    echo $i
    ./$prog < $i
    echo ""
done