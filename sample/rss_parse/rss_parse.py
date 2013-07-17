#!/usr/bin/python
# encoding: utf-8
import re
import sys
import math
import urllib2 as ul
import BeautifulSoup
import redis
import time
from datetime import date
import json
import bsddb

contents = {}
def fPrint(input):
  li = re.findall('href=\"(.*?)\".*?title=\"(.*?)\".*?>(.*?)<', str(input))
  if li == None or len(li) == 0:
    return
  tpl =  li[0]
  # 概要
  gai = tpl[1]
  # url
  url = tpl[0]
  contents.setdefault(gai, url);
def fFill(input):
  [s.extract() for s in input('span')]
  rehttp = re.compile('http*')
  [fPrint(s) for s in input('a', {'href':rehttp})]
  #[fPrint(s) for s in input('blockquote')]

def flushBDB(key):#BDBはキーのみを保存する
  db = bsddb.btopen('/tmp/nginx.dbm', 'w')
  keys = []
  if db.has_key('___DATEKEY___') == False or db['___DATEKEY___'] == None:
    db['___DATEKEY___'] = key;
    print 'set first key', db['___DATEKEY___']
    db.sync()
  else:
    print db['___DATEKEY___']
    db['___DATEKEY___'] = key + '\t' + db['___DATEKEY___']
    db.sync()
    print 'keys', db['___DATEKEY___']

if __name__ == '__main__':
  #はてブのプログラミング
  res = ul.urlopen('http://b.hatena.ne.jp/search/tag?q=%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0')
  html = res.read()
  soup = BeautifulSoup.BeautifulSoup(html)
  [s.extract() for s in soup('script')]
  [s.extract() for s in soup('meta')]
  [s.extract() for s in soup('a',{'class':'asin-image'})]
  [s.extract() for s in soup('cite')]
  [fFill(s) for s in soup('li',{'class':'search-result'})]
  rc = redis.Redis(host='127.0.0.1', port=6379, db=0)
  datekey = re.sub('-', '', str(date.today())) 
  lstdata = {'___RSS___': contents}
  jsn = json.dumps(lstdata, ensure_ascii=False)
  if rc.get(datekey) == None:
    rc.set(datekey, jsn)
    rc.get(datekey)
  else:
    #その日のデータにRSSを取得して追記する
    dc = json.loads(rc.get(datekey))
    dc.setdefault('___RSS___', contents)
    jsn = json.dumps(dc, ensure_ascii=False)
    rc.set(datekey, jsn)
    flushBDB(datekey)
  #print rc.get(datekey)


  #print jsn
