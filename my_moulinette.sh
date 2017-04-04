#! /bin/bash

# empty env
touch empty_env.txt
env -i ./mysh > tmp_empty_env.txt

diff empty_env.txt tmp_empty_env.txt > /dev/null
if [ $? -eq 0 ]
then
    echo "Empty Env - OK"
else
    echo "Empty Env - KO"
fi

rm -rf tmp_empty_env.txt
rm -rf empty_env.txt

# Plusieurs espaces
cat Makefile > cat_multiple_test.txt
echo "\n" >> cat_multiple_test.txt
echo -e "cat			Makefile" | ./mysh > tmp_cat_multiple_test.txt

diff cat_multiple_test.txt tmp_cat_multiple_test.txt > /dev/null
if [ $? -eq 0 ]
then
    echo "cat with tabs - OK"
else
    echo "cat with tabs - KO"
fi

rm -rf cat_multiple_test.txt
rm -rf tmp_cat_multiple_test.txt
