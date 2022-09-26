cat text6.txt | sed 's/hello//' > out.txt
u="$USER"
echo -n  "Family of $u: "
count=1
cat out.txt | while read line
do
   echo -n "$line"
   if [ $line != "daughter" ]; then
      echo -n ", "
   else
      echo -n "."
   fi
   count=$(( $count + 1 ))
done
