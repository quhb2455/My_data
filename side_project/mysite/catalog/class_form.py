from catalog.models import *

class CheckClassName :

    def CheckName(name):
        if 'Input' == name :
            return Input()

        if 'Conv2d' == name :
            return Conv2d()

        if 'MaxPooling2D' == name :
            return MaxPooling2D()



