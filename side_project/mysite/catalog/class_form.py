from catalog.models import *

class CheckClassName :

    def CheckName(name):
        if 'Input' == name :
            field = [name,'input_shape']
            return field

        if 'Conv2d' == name :
            field = [name,'_filter', 'activation_fuc' , 'padding', 'strides', 'kernel_size']
            return field

        if 'MaxPooling2D' == name :
            field = [name,'kernel_size', 'strides']
            return field



