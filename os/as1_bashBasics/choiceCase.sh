echo "enter any no from 1 to 7"
read no

case $no in
1)echo "Today is Mon";;
2)echo "Tue";;
3)echo "Wed";;
4)echo "THrr";;
5)echo "Fri";;
6)echo "sat";;
7)echo "holi";;
*)echo "invalid you";;
esac

echo "Today is `date`"
