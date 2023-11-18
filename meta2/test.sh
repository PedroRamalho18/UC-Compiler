# example: ./test.sh -t meta2
for i in $2/*.uc; do
    ./uccompiler $1 < "$i" |  diff -y "${i/%.uc}.out"-;
done
