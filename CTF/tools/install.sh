# binutils: strings
# netcat: nc
# dnsutils: dig
sudo apt install binutils nmap netcat dnsutils exiftool

git clone https://github.com/maurosoria/dirsearch.git dirsearch
git clone --depth 1 https://github.com/sqlmapproject/sqlmap.git sqlmap
git clone https://github.com/ReFirmLabs/binwalk.git binwalk && sudo python3 setup.py install