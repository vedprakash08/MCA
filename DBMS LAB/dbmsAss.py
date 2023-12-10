import pymysql
conn=pymysql.connect(host="127.0.0.1", user="root",password="", db="school")
cur=conn.cursor()

isContinue= True
while isContinue:
    print("1.Show Database")
    print("2.Create Table")
    print("3.Show Tables")
    print("4.Describe Table")
    print("5.Insert tuple")
    print("6.Delete tuple")
    print("7.Update tuple")
    print("8.Select Records")
    print("9.Exit")
    print("\n")
    choice=int(input("What you want to do: "))
    if choice==1:
          try:
              cur.execute(f'SHOW DATABASES;')
              rows=cur.fetchall()
              for row in rows:
                  print(row)
              print("Database Shown")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()         
    elif choice==2:
          try:
              cur.execute(f'CREATE TABLE IF NOT EXISTS student(rollno INT PRIMARY KEY, name VARCHAR(50), marks INT);')
              print("Table Created")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()             
    elif choice==3:
          try:
              cur.execute(f'SHOW TABLES;')
              rows=cur.fetchall()
              for row in rows:
                  print(row)
              print("Tables shown")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()
    elif choice==4:
          try:
              name=input("Enter table name: ")
              cur.execute(f'DESC {name};')
              rows=cur.fetchall()
              for row in rows:
                  print(row)
              print("Table Described")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()          
    elif choice==5:
          try:
              rollno=int(input("Enter roll number: "))
              name=input("Enter your name: ")
              marks=int(input("Enter your marks: "))
              cur.execute(f'INSERT INTO student VALUES({rollno},"{name}",{marks});')
              print("Tuple INSERTED")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()
    elif choice==6:
          try:
              rollno=int(input("Enter roll number: "))
              cur.execute(f'DELETE FROM student WHERE rollno={rollno};')
              print("Tuple Deleted")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()          
    elif choice==7:
          try:
              rollno=int(input("Enter roll number of tuple to update: "))
              name=input("Enter your name: ")
              marks=int(input("Enter your marks: "))
              cur.execute(f'UPDATE student SET name="{name}",marks={marks} WHERE rollno={rollno};')
              print("Tuple Updated")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()
    elif choice==8:
          try:
              name=input("Enter table name: ")
              cur.execute(f'SELECT * FROM {name};')
              rows=cur.fetchall()
              for row in rows:
                  print(row)
              print("Table display")
              conn.commit()
          except:
              print("ERROR OCCURED!")
              conn.rollback()          

    elif choice==9:
        isContinue= False
    else:
        print("Invalid choice")
        
