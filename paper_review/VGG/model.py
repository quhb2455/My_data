from keras.models import Model
from keras.layers.convolutional import Conv2D
from keras.layers import Activation, Dense, Flatten, MaxPooling2D, Input


#출처 : https://datascienceschool.net/view-notebook/d19e803640094f76b93f11b850b920a4/
# class LocalResponseNormalization(Layer):
#
#     def __init__(self, n=5, alpha=1e-4, beta=0.75, k=2, **kwargs):
#         self.n = n
#         self.alpha = alpha
#         self.beta = beta
#         self.k = k
#         super(LocalResponseNormalization, self).__init__(**kwargs)
#
#     def build(self, input_shape):
#         self.shape = input_shape
#         super(LocalResponseNormalization, self).build(input_shape)
#
#     def call(self, x):
#         _, r, c, f = self.shape
#         squared = K.square(x)
#         pooled = K.pool2d(squared, (self.n, self.n), strides=(1, 1), padding="same", pool_mode='avg')
#         summed = K.sum(pooled, axis=3, keepdims=True)
#         averaged = self.alpha * K.repeat_elements(summed, f, axis=3)
#         denom = K.pow(self.k + averaged, self.beta)
#         return x / denom
#
#     def compute_output_shape(self, input_shape):
#         return input_shape


def double_conv_max(filter) :
    def f(input) :

        conv1 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(input)
        activation1 = Activation("relu")(conv1)
        conv2 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation1)
        activation2 = Activation("relu")(conv2)
        max_conv = MaxPooling2D((2, 2), strides=2)(activation2)

        return max_conv
    return f


def triple_conv_max(filter):
    def f(input):
        conv1 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(input)
        activation1 = Activation("relu")(conv1)
        conv2 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation1)
        activation2 = Activation("relu")(conv2)
        conv3 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation2)
        activation3 = Activation("relu")(conv3)
        max_conv = MaxPooling2D((2, 2), strides=2)(activation3)

        return max_conv

    return f


def forth_conv_max(filter):
    def f(input):
        conv1 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(input)
        activation1 = Activation("relu")(conv1)
        conv2 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation1)
        activation2 = Activation("relu")(conv2)
        conv3 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation2)
        activation3 = Activation("relu")(conv3)
        conv4 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation3)
        activation4 = Activation("relu")(conv4)
        max_conv = MaxPooling2D((2, 2), strides=2)(activation4)

        return max_conv

    return f


def conv_max_11(filter,conv_1=False) :

    def f(input) :

        if filter < 255 :
            conv = Conv2D(filters=filter, kernel_size=(3,3), strides=(1,1), padding='same')(input)
            activation = Activation("relu")(conv)

            #LRN 구현 실패 - 최근엔 안쓰는 normalization 테크닉. 무시해도될듯.
            # if (LRN) & (filter==64):
            #     abc = Model(inputs=input, outputs=activation)
            #     lrn = LocalResponseNormalization(input_shape=abc.output_shape[1:])
            #     cba = Sequential()
            #     cba.add(lrn)
            #     max_conv = cba.add(MaxPooling2D((2,2),strides=2))
            #     # max_conv = MaxPooling2D((2,2),strides=2)(lrn)
            #     return  max_conv

            max_conv = MaxPooling2D((2, 2), strides=2)(activation)
            return max_conv

        elif filter >= 256 :
            result = double_conv_max(filter)(input)

            return result

    return f

def conv_max_13(filter, conv_1=False) :

    def f(input) :

        result = double_conv_max(filter)(input)

        return result

    return f


def conv_max_16(filter, conv_1 = False):

    def f (input) :

        if filter < 256:

            result = double_conv_max(filter)(input)

            return result

        elif filter >= 256:
            conv1 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(input)
            activation1 = Activation("relu")(conv1)
            conv2 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation1)
            activation2 = Activation("relu")(conv2)

            if conv_1 :
                conv3 = Conv2D(filters=filter, kernel_size=(1, 1), strides=(1, 1), padding='same')(activation2)
            else :
                conv3 = Conv2D(filters=filter, kernel_size=(3, 3), strides=(1, 1), padding='same')(activation2)

            activation3 = Activation("relu")(conv3)
            max_conv = MaxPooling2D((2, 2), strides=2)(activation3)

            return  max_conv

    return f

def conv_max_19(filter, conv_1=False):

    def f(input):

        if filter < 256:
            result = double_conv_max(filter)(input)

            return result

        elif filter >= 256:
            result = forth_conv_max(filter)(input)

            return result

    return f


def conv_block(conv_max,conv_1 = False):

    def f(input):
        filter = 64

        convolutional_layer = conv_max(filter,conv_1)(input)
        filter = filter * 2
        for i in range(4):
            convolutional_layer = conv_max(filter,conv_1)(convolutional_layer)
            if filter != 512:
                filter = filter * 2

        return convolutional_layer

    return f


def make_model(layer, conv_1 = False) :

    input = Input(shape=(224,224,3))

    filter = 64
    if layer == 11:
        convolutional_layer = conv_block(conv_max_11,conv_1)(input)

        # return convolutional_layer

    if layer == 13:
        convolutional_layer = conv_block(conv_max_13,conv_1)(input)

        # return convolutional_layer

    if layer == 16:
        convolutional_layer = conv_block(conv_max_16,conv_1)(input)


        # return convolutional_layer

    if layer == 19:
        convolutional_layer = conv_block(conv_max_19,conv_1)(input)

        # return convolutional_layer

    # if layer == 11 :
    #     # LRN_11 = LRN
    #     conv_block = Conv_layer(layer)(input)
    #
    # if layer == 13:
    #     conv_block = Conv_layer(layer)(input)
    #
    # if layer == 16 :
    #     conv1_16 = conv_1
    #     conv_block = Conv_layer(layer, conv1_16)(input)
    #
    # if layer == 19 :
    #     conv_block = Conv_layer(layer)(input)

    flatten = Flatten()(convolutional_layer)
    dense1 = Dense(units=4096, activation="relu")(flatten)
    dense2 = Dense(units=4096, activation="relu")(dense1)
    Last_layer = Dense(units=1000, activation="softmax")(dense2)
    model = Model(inputs=input, outputs=Last_layer)

    return model






