import time 
from selenium import webdriver

driver_path = "C:\\Users\\Aluno\\Documents\\Python Scripts\\chromedriver_win32\\chromedriver_win32.exe"
driver = webdriver.Chrome(driver_path)

driver.get("https://www.saucedemo.com/")

driver.find_element("css selector", "input#user-name").send_keys("standard_user")
time.sleep(1)
driver.find_element("css selector", "input#password").send_keys("secret_sauce")
time.sleep(1)
driver.find_element("css selector", "input.btn_action").click()
time.sleep(1)


time.sleep(1)

pageTitle = driver.find_element("css selector", "span.title")
assert pageTitle.text == "Products"

time.sleep(1)
driver.find_element("css selector", "button.btn_primary").click()
time.sleep(1)
driver.find_element("css selector", "a.shopping_cart_link").click()
time.sleep(1)

cartItem = driver.find_element("css selector", "div.inventory_item_name")
assert cartItem.text == "Sauce Labs Backpack"

driver.find_element("css selector", "button#checkout").click()
time.sleep(1)
driver.find_element("css selector", "input#first-name").send_keys("Carlos")
time.sleep(1)
driver.find_element("css selector", "input#last-name").send_keys("Lima")
time.sleep(1)
driver.find_element("css selector", "input#postal-code").send_keys("55555555")
time.sleep(1)
driver.find_element("css selector", "input#continue").click()
time.sleep(1)
driver.find_element("css selector", "input#finish").click()
time.sleep(1)
banner = driver.find_element("css selector", "h2.complete.header").click()
assert banner.text == "Thank you for your order!"
