ActionBar被设计成只能位于活动的顶部，从而不能实现Material Design的效果。ToolBar不仅继承了ActionBar的效果，而且更灵活，可以配合其他控件来完成一些Material Design的效果。
### 隐藏ActionBar
* 打开`res/values/styles.xml`文件

```xml
    <style name="AppTheme" parent="Theme.AppCompat.Light.NoActionBar">
        <!-- Customize your theme here. -->
        <item name="colorPrimary">@color/colorPrimary</item>
        <item name="colorPrimaryDark">@color/colorPrimaryDark</item>
        <item name="colorAccent">@color/colorAccent</item>
    </style>
```
