#Import tkinter library
from tkinter import *
#Create an instance of tkinter frame
win= Tk()
win.title("IOT Project GUI")
win.geometry("325x570")

#Define a function to highlight the text
def add_highlight():
   global text
   text.tag_add("selected", "1.00",END)
   text.tag_config("selected", background= "black", foreground= "white")
   global indexStart
   global indexEnd
   indexStart, indexEnd = text.tag_ranges("selected")
   highlighted = text.get(indexStart, indexEnd)
   print("Highlighted: ", highlighted)

def remove_Highlight():
   global text
   text.tag_delete("selected")
   print("removed highlight")

def deleteText():
   global text
   global lastDeletedText
   global lastDeletedStartIndex
   global indexStart
   global indexEnd
   if text.tag_ranges("selected"):
      lastDeletedText = text.get(indexStart, indexEnd)
      lastDeletedStartIndex = indexStart
      text.tag_delete("selected")
      text.delete(indexStart, indexEnd)
      print("text deleted", lastDeletedText)

def copyText():
   global text
   global indexStart
   global copiedText
   if text.tag_ranges("selected"):
      print("copy text between indexes: ", indexStart, indexEnd)
      copiedText = text.get(indexStart, indexEnd)
      print("Text copied", copiedText)
      return copiedText
   else:
      print("no selected text to copy")

def undo():
   global lastDeletedText
   global lastDeletedStartIndex
   global text
   if len(lastDeletedText) > 0:
      text.insert(lastDeletedStartIndex, lastDeletedText)
   print("undid change")

indexStart = ""
indexEnd = ""
copiedText = ""
lastDeletedText = ""
lastDeletedStartIndex = ""
lastDeletedEndIndex = ""

#Text Field
text= Text(win)
text.insert(INSERT, "Testing GUI")
text.pack()
#Create a Button to highlight text
Button(win, text= "Add highlight", command=add_highlight).pack()
#Create a Button to remove highlight
Button(win, text= "remove highlight", command=remove_Highlight).pack()
#Create a Button to delete highlight text
Button(win, text= "delete text", command=deleteText).pack()
#Create a Button to copy highlighted text
Button(win, text= "copy text", command=copyText).pack()
#Create a Button to undo delete
Button(win, text= "undo", command=undo).pack()
win.mainloop()
