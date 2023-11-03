#!bin/bash
# 1 -> Month directory
# 2 -> Problem name
# 3 -> Programming lang extension 
# 4 -> Solution
git pull 
cd $1
mkdir $2
cd $2
touch $2$3
echo $4 >> $2
git add .
git commit -m $2": "$3Solution Added
git push origin master
