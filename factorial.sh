echo "enter no to find factorial"
read myval
fact=1
while [ $myval -gt 1 ]
do
	fact=`expr $fact \* $myval`
	myval=`expr $myval - 1`
done
echo "$fact"
