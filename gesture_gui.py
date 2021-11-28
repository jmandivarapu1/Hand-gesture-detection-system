from tkinter import *

#tkinter frame instance
win= Tk()
win.title("IOT Project GUI")
win.geometry("360x570")

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

def moveToBeginningOfLine():
   global text
   text.mark_set("insert", "1.0")
   text.see("insert")
   print("moved cursor to beginning of line")

def moveToEndOfLine():
   global text
   text.mark_set("insert", "1.11")
   text.see("insert")
   print("moved cursor to end of line")

def get_location(event):
   global text
   global currentCursorLocationOnClick
   currentCursorLocationOnClick = text.index(CURRENT)
   print("location of click: ", currentCursorLocationOnClick)

indexStart = ""
indexEnd = ""
copiedText = ""
lastDeletedText = ""
lastDeletedStartIndex = ""
lastDeletedEndIndex = ""
currentCursorLocationOnClick = ""
#Text Field
text= Text(win)
text.insert(INSERT, "Testing GUI")
text.bind('<Button-1>', get_location)
text.pack()

#highlight text
Button(win, text= "Add highlight", command=add_highlight).pack()
#remove highlight
Button(win, text= "remove highlight", command=remove_Highlight).pack()
#delete highlight text
Button(win, text= "delete text", command=deleteText).pack()
#copy highlighted text
Button(win, text= "copy text", command=copyText).pack()
#undo delete
Button(win, text= "undo", command=undo).pack()
#move to beginning of line
Button(win, text= "move to beginning of line", command=moveToBeginningOfLine).pack()
#move to end of line
Button(win, text= "move to end of line", command=moveToEndOfLine).pack()

win.mainloop()