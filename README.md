# ElteTimetableConverter
At Eötvös Loránd University's Faculty of Economics (GTK), converting your timetable into a .csv file and importing it into Google Calendar 
can be a cumbersome process. To simplify this, I have developed a converter that automates this task.

## Usage
### On windows:
**Step 1:** Download the .exe file from the ***Releases*** section and click on the .exe file to download it.

**Step 2:** Copy your timetable from the ***GTK Inform system***. To do this, open GTK Inform, navigate to the timetable section, highlight the entire table including the header ('subject','time', etc.), copy it, and then paste it into a ***.txt*** file and save it.
The ***.txt*** file should look like this:

![image](https://github.com/user-attachments/assets/a5cbc254-6330-4e3e-ba63-180fcb2bd259)

The first line of the ***.txt*** file should contain the column headers. These can be in English; it does not matter. If there are empty rows or rows that do not contain relevant information, you can leave them in the file—the program will ignore them. In the image, the parts marked with '********' represent either the course code or the lecture code, which can be any value.

**Step 3:** Copy the ***.exe*** file into the same folder where the **.txt** file is located.
**Step 4:** Open ***Command Prompt*** (cmd) from the folder. To do this, open the folder, double-click on the address bar, type ***cmd***, and press Enter.

![image](https://github.com/user-attachments/assets/43af698d-fbb2-4fd6-9b83-bb3ffc9c5707)
A Command Prompt window will appear:
![image](https://github.com/user-attachments/assets/f220303d-a443-471f-a40b-99a9285de97b)

**Step 5:** Type ***serialize csvtool <filename>*** and press Enter. Replace ***<filename>*** with the name of your ***.txt*** file, including the ***.txt*** extension:

![image](https://github.com/user-attachments/assets/4f5a2757-0d8e-44bd-917d-ec03c421593f)

**Step 6:** Press Enter. If the ***.txt*** file is correctly formatted, the program will run successfully:

![image](https://github.com/user-attachments/assets/73c61f9e-fa26-4ea4-99a6-7261bf7f0af1)

The ***timetable.csv*** file will be generated in the same folder.

**Step 7:** You can now import the ***timetable.csv*** file into Google Calendar by following the steps provided in ***Google Help***: 

[Google Calendar Import Guide](https://support.google.com/calendar/answer/37118?hl=en&co=GENIE.Platform%3DDesktop)

## Warning

If the GTK Inform system changes its timetable format, the program may malfunction. I do not take responsibility for any missed events or inaccuracies in the calendar. The program is designed based on the timetable formatting used in the 2025/2 semester. If the format changes, updates to the program may be required to ensure compatibility. 
Any malfunctions or unexpected behaviors can be reported in the ***Issues*** section.


## License

This project is licensed under the [MIT License](https://choosealicense.com/licenses/mit/)

