#! /bin/bash

# empty env
env -i ./mysh > tmp_empty_env.txt

diff empty_env.txt tmp_empty_env.txt > /dev/null
if [ $? -eq 0 ]
then
    echo "Empty Env - OK"
else
    echo "Empty Env - KO"
fi

rm -rf tmp_empty_env.txt

# other test
