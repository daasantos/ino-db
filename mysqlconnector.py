#!usr/bin/python
import mysql.connector
import sys

RFID = sys.argv[1]

try: 
	db = mysql.connector.connect(host="localhost",    # your host, usually localhost
					user="stuff",        # your username
					passwd="morestuff",  # your password
					db="verystuff")      # name of the database
	if db.is_Connected():
		print "Connection sucessful."
	
	cursor = db.cursor()
	query = ("SELECT first_name, last_name FROM employees WHERE rfid = %s LIMIT 1;")
	cursor.execute(query, RFID)
	
	row = cursor.fetchone()
	if row == None:
		print row
		raise SystemExit
	
	while row is not None:
		print(row)
		row = cursor.fetchone()
	
except Error as e:
	print(e)
finally:
	cursor.close()
	cnx.close()
	raise SystemExit
