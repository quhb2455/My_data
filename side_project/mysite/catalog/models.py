from django.utils import timezone
from django.db import models
from django.conf import settings
# Create your models here.
# Member가 모델의 이름, 데이터베이스 테이블 이름이랑 비슷한듯;
# models.Model 는 앞의 클래스 이름이 모델이란 걸 의미하는 것


class Conv2d(models.Model) :
    _filter = models.IntegerField()
    kernel_size = models.CharField(max_length=20)
    strides = models.CharField(max_length=20)
    activation_fuc = models.CharField(max_length=50)
    padding = models.CharField(max_length=20)
    def publish(self):
        """Return the url to access a particular instance of MyModelName"""
        self.save()

class MaxPooling2D(models.Model) :
    kernel_size = models.CharField(max_length=20)
    strides = models.CharField(max_length=20)
    def publish(self):
        """Return the url to access a particular instance of MyModelName"""
        self.save()


class Input(models.Model) :
    input_shape = models.CharField(max_length=10)

    def publish(self):
        """Return the url to access a particular instance of MyModelName"""
        self.save()

class layers_name(models.Model) :
    name = models.CharField(max_length=20)

    def publish(self):
        """Return the url to access a particular instance of MyModelName"""
        self.save()




class Member(models.Model) :
    """A typical class defining a model, derived from the Model class."""

    #fields
    author = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    title = models.CharField(max_length=200)
    text = models.TextField()
    created_date = models.DateTimeField(
        default=timezone.now
    )
    published_date = models.DateTimeField(
        blank=True, null=True
    )
    #my_field_name = models.CharField(max_length=20, help_text='Enter field documentation')


    #Metadata


    #Methods
    def publish(self):
        """Return the url to access a particular instance of MyModelName"""
        self.published_date = timezone.now()
        self.save()


    def __str__(self):
        """String for representing the MyModelName object (in admin site etc..)"""
        return self.title