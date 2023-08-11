import socket # socket
import subprocess  # Subprocess
import time  # Time

def adb_connection(host, port):
  s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  s.connect((host, port))
  print(s.recv(1024))

  subprocess.call(['ssh -p 2222 -L 5555:localhost:5555 kristi@10.10.10.247'], shell=True)
  password = "Kr1sT!5h@Rp3xPl0r3!"
  print(s.recv(1024))

adb_connection("10.10.10.247", 2222)