.name           "42"
.comment        "Just a basic Winner Program"

pos1: live %0
live %0
live %0
live %0
zjmp %:pos3
pos2: live %0
live %0
ld 0, r6
live %0
live %0
zjmp %:pos1
pos3: live %0
live %0
live %0
live %0
live %0
zjmp %:pos2
