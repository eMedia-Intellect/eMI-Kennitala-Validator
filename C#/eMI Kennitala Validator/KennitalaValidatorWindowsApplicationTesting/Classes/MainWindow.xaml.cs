// <author>Stefán Örvar Sigmundsson</author>
// <copyright company="eMedia Intellect" file="MainWindow.xaml.cs">
//    Copyright © 2019 eMedia Intellect.
// </copyright>
// <licence>
//    This file is part of eMI Kennitala Validator.
//
//    eMI Kennitala Validator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    eMI Kennitala Validator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with eMI Kennitala Validator. If not, see http://www.gnu.org/licenses/.
// </licence>

namespace Emi.KennitalaValidatorWindowsApplicationTesting
{
	using System.Windows;
	using System.Windows.Media;
	using Emi.KennitalaValidator;

	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			this.InitializeComponent();
		}

		private void KennitalaTextBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
		{
			KennitalaType kennitalaType = Kennitala.Validate(this.kennitalaTextBox.Text);

			this.kennitalaTypeLabel.Content = kennitalaType;

			switch (kennitalaType)
			{
				case KennitalaType.Invalid:
					this.kennitalaTypeLabel.Foreground = Brushes.Red;

					break;
				case KennitalaType.Individual:
					this.kennitalaTypeLabel.Foreground = Brushes.Green;

					break;
				case KennitalaType.Organisation:
					this.kennitalaTypeLabel.Foreground = Brushes.Blue;

					break;
			}
		}
	}
}