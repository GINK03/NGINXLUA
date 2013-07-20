import urllib2
import socket
#response = urllib2.urlopen('http://127.0.0.1/bridge?namae=1&uname=test')

timeout = 10
socket.setdefaulttimeout(timeout)
i = 0
while(i<=1000):
  #response = urllib2.urlopen('http://127.0.0.1:8888/index.php')
  try:
    response = urllib2.urlopen('http://127.0.0.1/bridge?namae=1')
    html = response.read()
    i += 1
  except:
    pass
print html
