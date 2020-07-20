# Generated by Django 3.0.8 on 2020-07-20 14:35

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('catalog', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Conv2D',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('_filter', models.IntegerField()),
                ('kernel_size', models.IntegerField()),
                ('strides', models.IntegerField()),
                ('activation_fuc', models.CharField(max_length=50)),
                ('padding', models.CharField(max_length=20)),
            ],
        ),
        migrations.CreateModel(
            name='Input',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('input_shape', models.CharField(max_length=10)),
            ],
        ),
    ]
