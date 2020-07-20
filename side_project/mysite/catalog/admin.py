from django.contrib import admin
from .models import Member, Conv2d, Input, layers_name
# Register your models here.
# 여긴 관리자 페이지
admin.site.register(Member)
admin.site.register(Conv2d)
admin.site.register(Input)
admin.site.register(layers_name)

