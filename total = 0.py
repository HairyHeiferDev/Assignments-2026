

def child_info():
    age = 0
    child_ticket_price = 8
    num_of_child = input("how many children do you have?")
    child_age = input("whats your childs age?")
    child_total = 0
    num_of_child = int(num_of_child)
    child_age = int(child_age)
    child_total = int(child_total) 
    child_ticket_price = int(child_ticket_price)
    if int(child_age) <= 12 : print("adding kids pass")
    else: print("kids are not young enough for kids pass please purchase an adult pass")
    if num_of_child <= 1:
       child_total = num_of_child * child_ticket_price 
    else:
     child_total = child_total + child_ticket_price
    print("your child's total is:$",child_total)
    return child_total

def seniors_info():
    seniors_ticket_price = 10
    num_of_seniors = input("how many people are seniors 65+?")
    seniors_age = input("how many seniors are 65+?(if under 65 then buy a adult ticket 12-64age)")
    seniors_total = 0
    num_of_seniors = int(num_of_seniors)
    seniors_age = int(seniors_age)
    seniors_total = int(seniors_total) 
    seniors_ticket_price = int(seniors_ticket_price)
    if int(seniors_age) >= 65 : print("Welcome gramps/grandma")
    else: print("you still have youth please purchase an adult pass")
    seniors_total = num_of_seniors * 10 
    print("your senior's total is:$",seniors_total)
    return seniors_total


def collect_child_totals():
    child_total = child_info()
    return child_total

def collect_seniors_totals():
    seniors_total = seniors_info()
    return seniors_total

def final_reciept():
        child_total = child_info()
        seniors_total = seniors_info()
        Grand_total = child_total + seniors_total
        print("Child's total:", child_total, "Senior's total:", seniors_total, "Grand Total:", Grand_total)
        



   
child_info()
seniors_info()
collect_child_totals()
collect_seniors_totals()
final_reciept()
