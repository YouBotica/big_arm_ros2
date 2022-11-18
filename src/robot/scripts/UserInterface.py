import tkinter as tk
from tkinter import filedialog, Text
import os


root = tk.Tk()
    
canvas = tk.Canvas(root, height=700, width=700, bg="#263D42")
canvas.pack()

frame = tk.Frame(root, bg="white")
frame.place(relwidth=0.8, relheight=0.8, relx=0.1, rely=0.1)

openFile = tk.Button(root, text="Launch robot", padx=10, pady=5, fg="white", bg="#263D42")
openFile.place(x=350,y=350)

runApps = tk.Button(root, text="Stop robot", padx=10, pady=0, fg="white", bg="#263D42")
runApps.place(x=350, y=600)


root.mainloop()
